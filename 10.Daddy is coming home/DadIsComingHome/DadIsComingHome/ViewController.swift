//
//  ViewController.swift
//  DadIsComingHome
//
//  Created by Taro Minowa on 9/20/14.
//  Copyright (c) 2014 Higepon Taro Minowa. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    let device_id = "your_device_id"
    let access_token = "your_access_token"

    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor(red: 0.145, green: 0.145, blue: 0.145, alpha: 1.0)

        let screenWidth = UIScreen.mainScreen().bounds.size.width
        let screenHeight = UIScreen.mainScreen().bounds.size.height

        self.view.addSubview(createCircle(200, color:UIColor(red:0, green:0, blue:0, alpha: 1.0)))
        self.view.addSubview(createCircle(195, color:UIColor(red: 0.145, green: 0.145, blue: 0.145, alpha: 1.0)))
        self.view.addSubview(createCircle(185, color:UIColor(red:0, green:0, blue:0, alpha: 1.0)))
        self.view.addSubview(createCircle(180, color:UIColor(red:0.808, green:0.906, blue:0.271, alpha:1.0)))

        let button = UIButton.buttonWithType(UIButtonType.Custom) as UIButton
        button.frame = CGRectMake(
            (screenWidth - 200) / 2.0,
            (screenHeight - 200) / 2.0,
            200,
            200)
        button.setTitle("Coming home!", forState: UIControlState.Normal)
        button.titleLabel!.font = UIFont.boldSystemFontOfSize(22)
        button.addTarget(self, action: "pressed:", forControlEvents: .TouchUpInside)
        self.view.addSubview(button)

    }

    func pressed(sender: UIButton!)
    {

        var request = NSMutableURLRequest(URL: NSURL(string: "https://api.spark.io/v1/devices/\(device_id)/coming_home"))
        var session = NSURLSession.sharedSession()
        request.HTTPMethod = "POST"
        request.HTTPBody = "access_token=\(access_token)".dataUsingEncoding(NSUTF8StringEncoding)

        var task = session.dataTaskWithRequest(request, completionHandler: {data, response, error -> Void in
            println("Response: \(response)")
            var strData = NSString(data: data, encoding: NSUTF8StringEncoding)
            println("Body: \(strData)")
        })
        
        task.resume()
    }

    private func createCircle(radius: CGFloat, color: UIColor) -> UIView
    {
        let screenWidth = UIScreen.mainScreen().bounds.size.width
        let screenHeight = UIScreen.mainScreen().bounds.size.height
        let x = (screenWidth - radius) / 2.0
        let y = (screenHeight - radius) / 2.0

        let circle = UIView(frame: CGRectMake(x, y, radius, radius))
        circle.alpha = 0.5
        circle.layer.cornerRadius = radius / 2.0
        circle.backgroundColor = color
        return circle
    }
}
