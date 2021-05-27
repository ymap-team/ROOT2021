void TTreeWriteArray(){
  
  TFile *file = new TFile("TTreeArrayTest.root","RECREATE");
  TTree *tree = new TTree("tree","tree including array");
 
  double wfArray[100]={};
  
  tree->Branch("wfArray", wfArray, "wfArray[100]/D");

  for(int i=0;i<100;i++){

    for(int j=0;j<100;j++){

      wfArray[j] = i+j;
      
    }

    tree->Fill();
    
  }

  file->Write();
  file->Close();
  
}
