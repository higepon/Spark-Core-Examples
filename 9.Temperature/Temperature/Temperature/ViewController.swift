//
//  ViewController.swift
//  Temperature
//
//  Created by Taro Minowa on 9/14/14.
//  Copyright (c) 2014 Higepon Taro Minowa. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var reloadButton: UIButton!
    @IBOutlet weak var temperatureLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()

        // initial load
        reloadTemperature()
    }

    // when the reload button tapped
    @IBAction func reloadDidTap(sender: AnyObject) {
        reloadTemperature()
    }

    // call the API, parse the response and show result
    private func reloadTemperature() {
        let url = NSURL(string: "https://api.spark.io/v1/devices/53ff73065075535150531587/temperature?access_token=2154fc343dd4420ac61efbe55c625cf063706cb2")
        let request = NSURLRequest(URL: url)
        temperatureLabel.text = "Loading..."

        // call the API
        NSURLConnection.sendAsynchronousRequest(request, queue: NSOperationQueue.mainQueue()) {(response, data, error) in
            if error != nil {
                println("Request Error \(error.localizedDescription)")
                return;
            }
            var err: NSError?
            // parse the API response
            var jsonResult = NSJSONSerialization.JSONObjectWithData(data, options: NSJSONReadingOptions.MutableContainers, error: &err) as NSDictionary
            if err != nil {
                println("JSON Error \(err!.localizedDescription)")
            }
            println(jsonResult)
            if let temperature = jsonResult["result"] as? Float {
                // Show the result
                self.temperatureLabel.text = String(format: "%.2f°C", temperature)
            }
        }
    }
}

