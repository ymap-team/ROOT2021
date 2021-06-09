#include "TH1.h"
#include "TCanvas.h"
int main(){
  TCanvas *c = new TCanvas("c","c",800,600);
  TH1D *h = new TH1D("h","h",10,0,10);
  h->Fill(5);
  h->Draw();
  c->Print("c.png");
}
