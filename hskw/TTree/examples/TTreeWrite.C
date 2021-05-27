void TTreeWrite(){
  
  TFile *file = new TFile("TTreeTest.root","RECREATE");
  TTree *tree = new TTree("tree","Event Tree");

  int id, institute, year, env, network, nskill;
  double dt;
  bool ML, unix, shell, ROOT, cpp, python;

  // Registration order
  tree->Branch("id",        &id,        "id/I");

  // Institute
  // [Just a number. Names of institutes are not opened.]
  tree->Branch("institute", &institute, "institute/I");

  // Grade
  // [0:B4, 1:M1, 2:M2, 3:D1, 4:D2, 5:D3, 6:others]
  tree->Branch("year",      &year,      "year/I");

  // Computer environment
  // [1: Labo's Mac or Linux, 2: Labo's VM or remote machine,
  //  3: my Mac or Linux,    4: my windows, 5: I don't know, 0: others ]
  tree->Branch("env",       &env,       "env/I");

  // Network environment
  // [1: Fixed line at home, 2: Mobile line, 3: Labo's network, 4: I don't know, 0: others]
  tree->Branch("network",   &network,   "network/I");

  // Number of experienced programming languages
  tree->Branch("nskill",    &nskill,    "nskill/I");

  // Time difference of the registration from the first one. [second]
  tree->Branch("dt",        &dt,        "dt/D");

  // ML registration? [0: no, 1:yes]
  tree->Branch("ML",        &ML,        "ML/O");

  // Experience with this programming language? [0: no, 1:yes]
  tree->Branch("unix",      &unix,      "unix/O");
  tree->Branch("shell",     &shell,     "shell/O");
  tree->Branch("ROOT",      &ROOT,      "ROOT/O");
  tree->Branch("cpp",       &cpp,       "cpp/O");
  tree->Branch("python",    &python,    "python/O");


  ifstream ifs("./TTreeSeed.dat");
  if(!ifs.is_open()) {
    cout << "File not opened." << endl;
    return 0;
  }
  
  while(ifs >> id >> dt >> ML >> institute >> year >> env >> network >> unix >> shell >> ROOT >> cpp >> python){
    
    nskill = unix + shell + ROOT + cpp + python;

    tree->Fill();
  }
  
  file->Write();
  file->Close();
  
  return 0;
}
