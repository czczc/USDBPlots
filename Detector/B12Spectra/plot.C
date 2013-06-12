// From Xin Qian

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile *file = new TFile("B12_save.root");
  TH1F *hdata = (TH1F*)file->Get("Data");
  TH1F *hpred = (TH1F*)file->Get("Prediction");
  int rebin = 20;
  hpred->Rebin(rebin);
  hpred->Scale(1./rebin);

  TH1F *h_b12 = (TH1F*)file->Get("h_b12");
  TH1F *h_n12 = (TH1F*)file->Get("h_n12");
  TH1F *h_li9 = (TH1F*)file->Get("h_li9");
  TH1F *h_li8 = (TH1F*)file->Get("h_li8");
  TH1F *h_c9 = (TH1F*)file->Get("h_c9");
  TH1F *h_b8 = (TH1F*)file->Get("h_b8");

  TCanvas c1("c1", "c1", 800, 600);
  hdata->Draw();
  hdata->GetXaxis()->SetTitle("E_{rec} [MeV]");
  hdata->GetYaxis()->SetTitle("");
  hdata->SetTitle("^{12}B Spectra");

  hpred->SetLineColor(kRed);
  hpred->Draw("same");
  // h_n12->Draw("same");
  // h_b12->Draw("same");
  // h_li9->Draw("same");
  // h_li8->Draw("same");
  // h_c9->Draw("same");
  // h_b8->Draw("same");
  hdata->GetXaxis()->UnZoom();

  TString name("B12Spectra");

  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}
