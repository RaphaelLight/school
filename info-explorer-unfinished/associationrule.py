"""
File: associationrule.py
Resources in finding association rules.
"""

from openpyxl.workbook import Workbook
from openpyxl import load_workbook
from itemset import Itemset
from pyECLAT import ECLAT
import pandas

class AssociationRule(object):

    def __init__(self, dataFile, workSheet):
        self.itemsetX = Itemset(dataFile, workSheet)
        self.itemsetY = Itemset(dataFile, workSheet)
        self.itemsetZ = Itemset(dataFile, workSheet)

    def transaction_set_bin(self):
        transactionSetBin = self.itemsetX.transaction_set_bin()
        return transactionSetBin
    
    def transaction_set(self):
        transactionSet = self.itemsetX.transaction_set()
        return transactionSet

    def item_sets(self, itemset_X, itemset_Y):
        self.itemsetX.item_set(itemset_X)
        self.itemsetY.item_set(itemset_Y)
        itemSet = ""
        for item_x in self.itemsetX.itemset:
            itemSet += item_x + ','
        for item_y in self.itemsetY.itemset:
            contains = False
            for item_x in self.itemsetX.itemset:
                if item_y == item_x:
                    contains = True
                    break
            if contains == False:
                itemSet += item_y + ','
        self.itemsetZ.item_set(itemSet)

    def transaction_list(self):
        self.itemsetZ.count()
        return self.itemsetZ.transactionList

    def support(self):
        return float(self.itemsetZ.count()/len(self.transaction_set_bin().keys()))
    
    def confidence(self):
        return float(self.itemsetZ.count()/self.itemsetX.count())
    
    def lift(self):
        return float(self.itemsetZ.support()/(self.itemsetX.support()*self.itemsetY.support()))
    
    def strong_association(self, suppThreshold, confThreshold):
        if self.support() >= suppThreshold and self.confidence() >= confThreshold:
            return True
    
    def auto_find(self, suppThreshold, min_combo):
        transactionSet = pandas.DataFrame(self.transaction_set())
        minSupport = suppThreshold
        minCombo = min_combo
        maxCombo = max([len(x) for x in self.transaction_set()])

        eclat = ECLAT(transactionSet)
        ruleIndices, ruleSupports = eclat.fit(minSupport, minCombo, maxCombo, ', ', False)

        return ruleSupports
