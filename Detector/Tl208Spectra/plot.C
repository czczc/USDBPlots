// From Xin Qian

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile *file = new TFile("mc.root");
  TH1F *mc = (TH1F*)file->Get("h1");

  TFile *gile = new TFile("TlExample.root");
  TH1F *data = (TH1F*)gile->Get("sig0");
  mc->Rebin(100);
  mc->Scale(data->Integral(data->FindBin(3.5),data->FindBin(5))/mc->Integral(mc->FindBin(3.5),mc->FindBin(5)));

  TCanvas c1("c1","c1",800, 600);
  data->SetXTitle("E_{rec} [MeV]");
  data->SetYTitle("");
  data->SetTitle("^{208}Tl Spectra");
  data->GetYaxis()->SetRangeUser(0, 1200);
  data->Draw();
  mc->SetLineColor(kRed);
  mc->Draw("same");

  TString name("Tl208Spectra");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}
