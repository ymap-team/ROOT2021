void TTreeReadArray(){

  TFile file("./TTreeArrayTest.root");
  TTree *tree = (TTree*)file.Get("tree");

  double wfArray[100]={};

  tree->SetBranchAddress("wfArray", wfArray);

  for(int i=0;i<tree->GetEntries();i++){
    tree->GetEntry(i);
    
    for(int j=0;j<100;j++){
      cout << wfArray[j] << endl;
    }
  }
}
