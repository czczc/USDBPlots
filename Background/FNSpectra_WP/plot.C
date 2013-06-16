// From Jiajie Ling & Chao Zhang

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("fast_spec_eh1.root");
  TH1F *eh1 = (TH1F*)f1.Get("fastn_side");
  TFile f2("fast_spec_eh2.root");
  TH1F *eh2 = (TH1F*)f2.Get("fastn_side");
  TFile f3("fast_spec_eh3.root");
  TH1F *eh3 = (TH1F*)f3.Get("fastn_side");

  TCanvas c1("c1", "c1", 800, 600);
  eh1->Draw("e");
  eh1->GetXaxis()->SetTitle("Reconstructed Energy [MeV]");
  eh1->GetYaxis()->SetTitle("");
  // eh1->GetXaxis()->SetRangeUser(0.71, 50);
  eh1->GetYaxis()->SetRangeUser(1, 550);
  eh1->SetTitle("Fast Neutron Spectrum Tagged by Water Pool");

  eh2->SetLineColor(kBlue);
  eh2->Draw("e, same");

  eh3->SetLineColor(kMagenta);
  eh3->Draw("e, same");

  TLegend leg2(0.80,0.96,0.90,0.96-3*0.06);
  leg2.SetFillColor(kWhite);
  leg2.SetBorderSize(1);
  leg2.AddEntry(eh1, " EH1", "l");
  leg2.AddEntry(eh2, " EH2", "l");
  leg2.AddEntry(eh3, " EH3", "l");
  leg2.Draw();

  // gPad->SetLogy();

  TString name("FNSpectra_WP");
  // print 3 figures by default
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}