// From Chao Zhang

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("R2Z.root");
  TH2F *hp1 = (TH2F*)f1.Get("R2Z_EH1AD1");
  TH2F *hp2 = (TH2F*)f1.Get("R2Z_EH1AD2");
  TH2F *hp3 = (TH2F*)f1.Get("R2Z_EH2AD1");
  TH2F *hp4 = (TH2F*)f1.Get("R2Z_EH4AD1");
  TH2F *hp5 = (TH2F*)f1.Get("R2Z_EH4AD2");
  TH2F *hp6 = (TH2F*)f1.Get("R2Z_EH4AD3");

  TCanvas c1("c1", "c1", 900, 600);
  c1.Divide(3,2);

  c1.cd(1);
  hp1->Draw("colz");

  c1.cd(2);
  hp2->Draw("colz");

  c1.cd(3);
  hp3->Draw("colz");

  c1.cd(4);
  hp4->Draw("colz");

  c1.cd(5);
  hp5->Draw("colz");

  c1.cd(6);
  hp6->Draw("colz");

  TString name("VertexR2Z");
  // print 3 figures by default
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}
