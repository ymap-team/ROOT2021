#!/bin/bash

cp TTreeTest.root TTreeTest1.root
cp TTreeTest.root TTreeTest2.root

hadd sum0.root TTreeTest.root TTreeTest1.root TTreeTest2.root
hadd sum1.root TTreeTest*.root
