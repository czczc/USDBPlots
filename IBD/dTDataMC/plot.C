void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("mc.root");
  TH1F *mc = (TH1F*)f1.Get("time_onGd");
  TFile f2("dT.root");
  TH1F *data = (TH1F*)f2.Get("Dt_EH1-AD1");
  data->Rebin(2);
  mc->Scale(data->Integral(0,200)/mc->Integral(1,200) * data->GetBinWidth(1)/mc->GetBinWidth(1));

  TCanvas c1("c1", "c1", 800, 600);
  mc->SetLineColor(kRed);
  mc->Draw();
  mc->SetTitle("");
  mc->GetXaxis()->SetTitle("#DeltaT_{p-d} [#mus]");
  mc->GetYaxis()->SetTitle("");
  mc->GetXaxis()->SetRangeUser(0,300);
  data->SetLineColor(kBlack);
  data->SetMarkerStyle(24);
  data->SetMarkerSize(0.7);
  data->Draw("same,ep");
  gPad->SetLogy();

  TLegend leg(0.65,0.85-0.20,0.85,0.85);
  leg.AddEntry(data, " Data", "lp");
  leg.AddEntry(mc, " MC", "l");
  leg.SetFillColor(kWhite);
  leg.Draw();

  TString name("dTDataMC");
  c1.SaveAs(name + "." + type);
}