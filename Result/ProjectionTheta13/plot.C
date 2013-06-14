// From Jiajie Ling

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");
  TCanvas c1("c1", "c1", 800, 600);
  c1.SetLeftMargin(0.14);

  double time_6AD[4] = {55., 100., 150., 215.};
  double t13_6AD_rate[4] = {0.0168045, 0.0127836, 0.010693, 0.00918313};
  double t13_6AD = 0.00823358;
  double dm32_6AD = 0.000179493;

  double time_8AD[15] = {0, 55, 100, 150, 215, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200};
  double t13_8AD_rate[15] = {1000, 0.0145753, 0.0110718, 0.00925961, 0.00795926,
			     0.00697491, 0.006271, 0.00580699, 0.00547553, 0.00522585,
			     0.00503048, 0.00487316, 0.00474361, 0.00463499, 0.00454255};
  double t13_8AD[15] = {1000, 0.0135755, 0.0102089, 0.00845552, 0.00718316, 0.00619338,
			0.00548116, 0.00498892, 0.00462814, 0.00434865, 0.00413778,
			0.00393958, 0.00378387, 0.00366287, 0.00354724};
  double dm32_8AD[15] = {1000, 0.000276134, 0.000213527, 0.00018044, 0.000155892,
			 0.000136424, 0.00012168, 0.000111419, 0.000103666, 9.75105e-05,
			 9.24441e-05, 8.81705e-05, 8.45027e-05, 8.13015e-05, 7.84739e-05};

  for (int i=0; i<15; i++) {
    time_8AD[i] += 295.;
    t13_8AD_rate[i] = 1./sqrt( 1./(t13_6AD_rate[3]*t13_6AD_rate[3]) + 1./(t13_8AD_rate[i]*t13_8AD_rate[i]) );
    t13_8AD[i] = 1./sqrt( 1./(t13_6AD*t13_6AD) + 1./(t13_8AD[i]*t13_8AD[i]) );
    dm32_8AD[i] = 1./sqrt( 1./(dm32_6AD*dm32_6AD) + 1./(dm32_8AD[i]*dm32_8AD[i]) );
    dm32_8AD[i] *= 1000;
   }

  TLine *l = new TLine(215, t13_6AD_rate[3], 295, t13_6AD_rate[3]);
  l->SetLineWidth(2);
  l->SetLineStyle(2);
  l->SetLineColor(6);

  TMarker *rate_prl = new TMarker(55, sqrt(0.016*0.016+0.005*0.005), 20);
  rate_prl->SetMarkerSize(1);
  rate_prl->SetMarkerColor(2);

  TMarker *rate_cpc = new TMarker(139, sqrt(0.01*0.01+0.005*0.005), 20);
  rate_cpc->SetMarkerSize(1);
  rate_cpc->SetMarkerColor(4);

  TH2D *h1 = new TH2D("h1", "Projected Daya Bay Sensitivity of sin^{2}2#theta_{13} (68% C.L.)", 100, 0, 1600, 100, 0, 0.02);
  h1->SetXTitle("Time(Days)");
  h1->SetYTitle("#delta(sin^{2}2#theta_{13})");
  h1->SetTitleOffset(1.5, "y");

  TGraph* t13_rate_6AD_gr = new TGraph(4,  time_6AD, t13_6AD_rate);
  TGraph* t13_rate_8AD_gr = new TGraph(15, time_8AD, t13_8AD_rate);
  TGraph* t13_gr = new TGraph(15, time_8AD, t13_8AD);

  t13_rate_6AD_gr->SetLineWidth(2);
  t13_rate_8AD_gr->SetLineWidth(2);
  t13_gr->SetLineWidth(2);

  t13_gr->SetLineColor(4);

  h1->Draw();
  t13_rate_6AD_gr->Draw("c,same");
  t13_rate_8AD_gr->Draw("c,same");
  t13_gr->Draw("c,same");
  rate_prl->Draw();
  rate_cpc->Draw();
  l->Draw();

  TLegend *leg = new TLegend(0.6, 0.6, 0.85, 0.85);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(t13_rate_6AD_gr, "Rate Only 6->8AD", "l");
  leg->AddEntry(l, "Installation", "l");
  leg->AddEntry(t13_gr, "Rate+Shape", "l");
  leg->AddEntry(rate_prl, "PRL 108 171803", "p");
  leg->AddEntry(rate_cpc, "CPC 37 011001", "p");

  leg->Draw();
  TString name("ProjectionTheta13");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }


  // TH2D *h2 = new TH2D("h2", "Projected Daya Bay Sensitivity of #Deltam^{2}_{ee} (68% C.L.)", 100, 0, 1600, 100, 0, 0.25);
  // h2->SetXTitle("Time(Days)");
  // h2->SetYTitle("#delta(#Delta m^{2}_{ee}) (10^{-3}eV^{2})");

  // TCanvas *c2 = new TCanvas("c2", "c2", 800, 600);
  // TGraph* dm32_gr = new TGraph(15, time_8AD, dm32_8AD);
  // h2->Draw();
  // dm32_gr->Draw("c,same");
  // dm32_gr->SetLineWidth(2);
  // dm32_gr->SetLineColor(4);

  // TLegend *leg2 = new TLegend(0.6, 0.6, 0.8, 0.8);
  // leg2->SetBorderSize(0);
  // leg2->AddEntry(dm32_gr, "Rate+Shape", "lp");
  // leg2->Draw();

  // TLatex *lax = new TLatex();
  // lax->SetTextSize(0.035);
  // lax->DrawLatex(1000, 0.22, "Assuming sin^{2}2#theta_{13} = 0.1");

  // c2->Print("dmee.png");
  // c2->Print("dmee.eps");
}
