//
//  LogViewController.swift
//  RWRealmStarterProject
//
//  Created by Bill Kastanakis on 8/7/14.
//  Copyright (c) 2014 Bill Kastanakis. All rights reserved.
//

import UIKit
import Realm
import MapKit

class LogViewController: UITableViewController, UISearchResultsUpdating, UISearchBarDelegate {
  
    var specimens : RLMResults!
    var searchResults : RLMResults!
  
  @IBOutlet weak var segmentedControl: UISegmentedControl!
  
  var searchController : UISearchController!
  
  // MARK: - SearchBar Delegate
  // You can use objectsWhere but let's introduce predicates! :]
  
  func updateSearchResultsForSearchController(searchController: UISearchController) {
    let searchString = searchController.searchBar.text
        
    let searchResultsController = searchController.searchResultsController as! UITableViewController
    searchResultsController.tableView.reloadData()
  }
  
  // MARK: - View Lifecycle
  
  override func viewDidLoad() {
    super.viewDidLoad()
    specimens = Specimen.allObjects().sortedResultsUsingProperty("name", ascending: true)
    
    var searchResultsController = UITableViewController(style: .Plain) as UITableViewController
    searchResultsController.tableView.delegate = self
    searchResultsController.tableView.dataSource = self
    searchResultsController.tableView.rowHeight = 63
    searchResultsController.tableView.registerClass(LogCell.self, forCellReuseIdentifier: "LogCell")
    
    searchController = UISearchController(searchResultsController: searchResultsController)
    searchController.searchResultsUpdater = self
    searchController.searchBar.sizeToFit()
    searchController.searchBar.tintColor = UIColor.whiteColor()
    searchController.searchBar.delegate = self
    searchController.searchBar.barTintColor = UIColor(red: 0, green: 104.0/255.0, blue: 55.0/255.0, alpha: 1.0)
    tableView.tableHeaderView?.addSubview(searchController.searchBar)
    
    definesPresentationContext = true;
    
  }
  
  override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
  }
  
  // MARK: - Table view data source
  
  override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
    return 1
  }
  
  override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    
    if searchController.active {
        if searchResults == nil {
            return 0
        }
        return Int(searchResults.count)
    }
    else
        if specimens == nil {
            return 0
        }
        return Int(specimens.count)
    }
    
  
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var cell = tableView.dequeueReusableCellWithIdentifier("LogCell") as! LogCell
        var specimen: Specimen!
        
        if (searchController.active && searchResults.count > 0) {
            specimen = searchResults[UInt(indexPath.row)] as! Specimen
        } else {
            specimen = specimens[UInt(indexPath.row)] as! Specimen
        }
        cell.titleLabel.text = specimen.name
        cell.subtitleLabel.text = specimen.category.name
        
        switch specimen.category.name {
        case "Uncategorized":
            cell.iconImageView.image = UIImage(named: "IconUncategorized")
        case "Reptiles":
            cell.iconImageView.image = UIImage(named: "IconReptile")
        case "Flora":
            cell.iconImageView.image = UIImage(named: "IconFlora")
        case "Birds":
            cell.iconImageView.image = UIImage(named: "IconBird")
        case "Arachnid":
            cell.iconImageView.image = UIImage(named: "IconArachnid")
        case "Mammals":
            cell.iconImageView.image = UIImage(named: "IconMammal")
        default:
            cell.iconImageView.image = UIImage(named: "IconUncategorized")
        }
        
        return cell
    }
  
  override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) -> Bool {
    return true
  }
  
  override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
    if editingStyle == .Delete {
        deleteRowAtIndexPath(indexPath)
    }
  }
  
  override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject!) {
    if (segue.identifier == "Edit") {
      let controller = segue.destinationViewController as! AddNewEntryController
      
      let indexPath = tableView.indexPathForSelectedRow()
      
      if searchController.active {
        let searchResultsController = searchController.searchResultsController as! UITableViewController
        let indexPathSearch = searchResultsController.tableView.indexPathForSelectedRow()
        
      }
    }
    }
    
    func deleteRowAtIndexPath(indexPath: NSIndexPath) {
        let realm = RLMRealm.defaultRealm() //1
        let objectToDelete = specimens[UInt(indexPath.row)] as! Specimen //2
        realm.beginWriteTransaction() //3
        realm.deleteObject(objectToDelete) //4
        realm.commitWriteTransaction() //5
        
        specimens = Specimen.allObjects().sortedResultsUsingProperty("name", ascending: true) //6
        
        tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Fade) //7
    }
    
    func searchBar(searchBar: UISearchBar, textDidChange searchText: String) {
        filterResultsWithSearchString(searchText)
    }
    func filterResultsWithSearchString(searchString: String) {
        let predicate = NSPredicate(format: "name BEGINSWITH [c]%@", searchString) // 1
        let scopeIndex = searchController.searchBar.selectedScopeButtonIndex
        switch scopeIndex {
        case 0:
            searchResults = Specimen.objectsWithPredicate(predicate).sortedResultsUsingProperty("name", ascending: true) //2
        case 1:
            searchResults = Specimen.objectsWithPredicate(predicate).sortedResultsUsingProperty("distance", ascending: true) //3
        case 2:
            searchResults = Specimen.objectsWithPredicate(predicate).sortedResultsUsingProperty("created", ascending: true) //4
        default:
            searchResults = Specimen.objectsWithPredicate(predicate)
        }
    }
  
  
  //MARK: - Actions

  @IBAction func scopeChanged(sender: AnyObject) {

        let scopeBar = sender as! UISegmentedControl
        
        switch scopeBar.selectedSegmentIndex {
        case 0:
            specimens = Specimen.allObjects().sortedResultsUsingProperty("name", ascending: true)
        case 1:
            break
        case 2:
            specimens = Specimen.allObjects().sortedResultsUsingProperty("created", ascending: true)
        default:
            specimens = Specimen.allObjects().sortedResultsUsingProperty("name", ascending: true)
        }
        tableView.reloadData()
    }
  
}
