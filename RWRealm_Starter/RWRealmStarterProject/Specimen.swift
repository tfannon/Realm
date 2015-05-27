//
//  Specimen.swift
//  RWRealmStarterProject
//
//  Created by Tommy Fannon on 5/23/15.
//  Copyright (c) 2015 Bill Kastanakis. All rights reserved.
//



import Realm

class Specimen: RLMObject {
    dynamic var name = ""
    dynamic var specimenDescription = ""
    dynamic var latitude: Double = 0.0
    dynamic var longitude: Double = 0.0
    dynamic var created = NSDate()
    
    dynamic var category = Category()
}
