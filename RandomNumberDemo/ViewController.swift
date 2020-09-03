//
//  ViewController.swift
//  RandomNumberDemo
//
//  Created by Amit on 15/08/20.
//  Copyright © 2020 Amit. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var lblDisplayText: UILabel!
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
    }

    @IBAction func btnGenerateNumberAction(_ sender: Any) {
        self.lblDisplayText.text = "Random Number: \(generateRandomNumber())"
       generate_key()
    }
    
}

