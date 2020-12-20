//
//  UITableView+Utilities.swift
//  VSeeClinicKit
//
//  Created by dat on 12/8/17.
//  Copyright © 2017 vsee. All rights reserved.
//

import Foundation

public extension UITableViewController {
    public func reRefreshControlIfIsRefreshing() {
        if let refreshControl = self.refreshControl,
            refreshControl.isRefreshing {
            let offset = self.tableView.contentOffset
            self.refreshControl?.endRefreshing()
            self.refreshControl?.beginRefreshing()
            self.tableView.contentOffset = offset
        }
    }
}
