//
//  UserDefaults.swift
//  ThoroughbredInsider
//
//  Created by Diazz on 06/08/18.
//  Copyright © 2018 clinic. All rights reserved.
//

import UIKit

/**
 * User defaults wrapper
 *
 * - author: Diazz
 * - version: 1.0
 */
@objc public extension UserDefaults {

    /// increasePhotoLocalId
    @objc public static var increasePhotoLocalId: Int {
        get {
            var id = standard.integer(forKey: "increasePhotoLocalId")
            id += 1;
            // if id is too big, reset to 1
            if (id >= UInt8.max) {
                id = 1;
            }
            standard.set(id, forKey: "increasePhotoLocalId")
            standard.synchronize()
            return id
        }
    }
    
    /// increaseCommentLocalId
    @objc public static var increaseCommentLocalId: Int {
        get {
            var id = standard.integer(forKey: "increaseCommentLocalId")
            id += 1;
            // if id is too big, reset to 1
            if (id >= UInt8.max) {
                id = 1;
            }
            standard.set(id, forKey: "increaseCommentLocalId")
            standard.synchronize()
            return id
        }
    }
    
//    /// first story launch flag
//    static var firstStoryLaunch: Bool {
//        get {
//        return standard.bool(forKey: "firstStoryLaunch")
//        }
//        set {
//            standard.set(newValue, forKey: "firstStoryLaunch")
//            standard.synchronize()
//        }
//    }
    
}
