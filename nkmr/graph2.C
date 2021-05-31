{
  double gen[3]={1.5, 2.5, 3.5};
  double mass[3]={2.16, 93, 4.18e3};
  TGraph *g = new TGraph(3, gen, mass);
  g->Draw();
}
