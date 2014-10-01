require "rubygems"
require "google_drive"
require "json"
require "net/https"
require "uri"
require "pp"

def get_temperature
  # Call temperature API!
  uri = URI.parse("https://api.spark.io/v1/devices/#{ENV['DEVICE_ID']}/temperature?access_token=#{ENV['ACCESS_TOKEN']}")
  http = Net::HTTP.new(uri.host, uri.port)
  http.use_ssl = true
  http.verify_mode = OpenSSL::SSL::VERIFY_NONE
  request = Net::HTTP::Get.new(uri.request_uri)
  response = http.request(request)

  if response.code == "200"
    result = JSON.parse(response.body)
    return result["result"]
  else
    return nil
  end
rescue
  return nil
end

i = 1
while true do
  begin
    t = get_temperature
    if t
      # Logs in to Google
      session = GoogleDrive.login(ENV['GOOGLE_ID'], ENV['GOOGLE_PASSWORD'])

      # First worksheet of
      # https://docs.google.com/spreadsheet/ccc?key=18vExmI-c05Py8jSX7KgNmSTsDFn7i2bxsvwXWA1cZ3I
      ws = session.spreadsheet_by_key("18vExmI-c05Py8jSX7KgNmSTsDFn7i2bxsvwXWA1cZ3I").worksheets[0]
      ws[i, 1] = Time.new
      ws[i, 2] = t
      puts t
      ws.save
      i = i + 1
    end
    sleep 60
  rescue
    sleep 60
  end
end
