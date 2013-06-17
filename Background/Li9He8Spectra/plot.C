// From Jiajie Ling & Chao Zhang

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("li9spec2.root");
  TH1F *eh1 = (TH1F*)f1.Get("data_eh1");
  TH1F *eh2 = (TH1F*)f1.Get("data_eh2");
  TH1F *eh3 = (TH1F*)f1.Get("data_eh3");
  TFile f2("Li9-1.root");
  TH1F *theory = (TH1F*)f2.Get("h1");
  theory->Rebin(10);
  // theory->Smooth();

  eh1->Add(eh2);
  eh1->Add(eh3);
  TCanvas c1("c1", "c1", 800, 600);
  eh1->Draw("e");
  eh1->GetXaxis()->SetTitle("Reconstructed Energy [MeV]");
  eh1->GetYaxis()->SetTitle("");
  // eh1->GetXaxis()->SetRangeUser(0.71, 50);
  // eh1->GetYaxis()->SetRangeUser(1, 550);
  eh1->SetTitle("^{9}Li / ^{8}He Spectra");

  theory->Scale(eh1->Integral(eh1->FindBin(1), eh1->FindBin(12))
    /eh1->GetBinWidth(1)
    /theory->Integral(theory->FindBin(1), theory->FindBin(12))
    /theory->GetBinWidth(1)
  );
  theory->SetLineColor(kRed);
  // theory->SetLineStyle(2);
  theory->Draw("same");
  // gPad->SetLogy();

  TString name("Li9He8Spectra");
  // print 3 figures by default
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}