// From Xin Qian

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile *file1 = new TFile("bi214_plot.root");
  TH1F *h1 = (TH1F*)file1->Get("h1");
  TH1F *h2 = (TH1F*)file1->Get("h2");
  h1->Rebin();
  h2->Rebin();

  TCanvas c1("c1","c1",800,600);
  h2->Draw();
  h2->GetXaxis()->SetTitle("E_{rec} [MeV]");
  h2->GetYaxis()->SetTitle("");
  h2->SetTitle("^{214}Bi Spectra");
  h2->GetXaxis()->SetRangeUser(1.2, 3);

  h1->SetLineColor(kRed);
  h1->Draw("same");

  TString name("Bi214Spectra");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }

}
