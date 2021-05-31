{
  double gen[3] = {1.5, 2.5, 3.5};
  double mass[3] = {2.16, 93, 4.18e3};
  double ex1[3] = {0.1, 0.1, 0.1};
  double ex2[3] = {0.9, 0.9, 0.9};
  double ey1[3] = {0.26,  5, 0.02e3};
  double ey2[3] = {0.49, 11, 0.03e3};
  TGraphAsymmErrors *g = new TGraphAsymmErrors(3, gen, mass, ex1, ex2, ey1, ey2);
  g->Draw();
}

