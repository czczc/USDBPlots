// From Jiajie Ling & Chao Zhang

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("fn_all.root");
  TH1F *eh1 = (TH1F*)f1.Get("eh1_hist");
  TH1F *eh2 = (TH1F*)f1.Get("eh2_hist");
  TH1F *eh3 = (TH1F*)f1.Get("eh3_hist");

  TCanvas c1("c1", "c1", 800, 600);
  eh1->Draw("e");
  eh1->GetXaxis()->SetTitle("Reconstructed Energy [MeV]");
  eh1->GetYaxis()->SetTitle("");
  eh1->GetXaxis()->SetRangeUser(0.71, 50);
  eh1->GetYaxis()->SetRangeUser(1, 2e5);
  eh1->SetTitle("Fast Neutron Spectrum Tagged by AD");

  eh2->SetLineColor(kBlue);
  eh2->Draw("e, same");

  eh3->SetLineColor(kMagenta);
  eh3->Draw("e, same");

  TLegend leg2(0.70,0.89,0.89,0.89-3*0.06);
  leg2.SetFillColor(kWhite);
  leg2.AddEntry(eh1, " EH1", "l");
  leg2.AddEntry(eh2, " EH2", "l");
  leg2.AddEntry(eh3, " EH3", "l");
  leg2.Draw();

  gPad->SetLogy();

  TString name("FNSpectra_AD");
  // print 3 figures by default
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}