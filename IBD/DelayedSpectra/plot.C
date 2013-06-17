// From Chao Zhang

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("Ed.root");
  TH1F *hp1 = (TH1F*)f1.Get("Ed_EH1-AD1");
  TH1F *hp2 = (TH1F*)f1.Get("Ed_EH1-AD2");
  TH1F *hp3 = (TH1F*)f1.Get("Ed_EH2-AD1");
  TH1F *hp4 = (TH1F*)f1.Get("Ed_EH3-AD1");
  TH1F *hp5 = (TH1F*)f1.Get("Ed_EH3-AD2");
  TH1F *hp6 = (TH1F*)f1.Get("Ed_EH3-AD3");

  TCanvas c1("c1", "c1", 800, 600);
  hp1->Draw("");
  hp1->GetXaxis()->SetTitle("Reconstructed Energy [MeV]");
  hp1->GetXaxis()->SetRangeUser(6, 12);
  hp1->SetTitle("Delayed Spectra");

  hp2->SetLineColor(kBlue);
  hp2->Draw("same");

  hp3->SetLineColor(kRed);
  hp3->Draw("same");

  hp4->SetLineColor(kCyan+1);
  hp4->Draw("same");

  hp5->SetLineColor(kMagenta);
  hp5->Draw("same");

  hp6->SetLineColor(kGreen+2);
  hp6->Draw("same");


  TLegend leg1(0.51,0.89,0.70,0.89-3*0.06);
  TLegend leg2(0.70,0.89,0.89,0.89-3*0.06);
  leg1.SetFillColor(kWhite);
  leg1.SetBorderSize(1);
  leg2.SetFillColor(kWhite);
  leg2.SetBorderSize(1);

  leg1.AddEntry(hp1, " EH1-AD1", "l");
  leg1.AddEntry(hp2, " EH1-AD2", "l");
  leg1.AddEntry(hp3, " EH2-AD1", "l");
  leg2.AddEntry(hp4, " EH3-AD1", "l");
  leg2.AddEntry(hp5, " EH3-AD2", "l");
  leg2.AddEntry(hp6, " EH3-AD3", "l");

  leg1.Draw();
  leg2.Draw();

  // gPad->SetLogy();

  TString name("DelayedSpectra");
  // print 3 figures by default
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}
