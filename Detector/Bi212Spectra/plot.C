// From Xin Qian

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile *file1 = new TFile("bi212_plot.root");
  TH1F *h1 = (TH1F*)file1->Get("h1");
  TH1F *h2 = (TH1F*)file1->Get("h2");

  TCanvas c1("c1","c1",800,600);
  h2->Draw();
  h2->GetXaxis()->SetTitle("E_{rec} [MeV]");
  h2->GetYaxis()->SetTitle("");
  h2->SetTitle("^{212}Bi Spectra");

  h1->SetLineColor(kRed);
  h1->Draw("same");

  TString name("Bi212Spectra");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }

}
