#!/usr/bin/env bash

pdflatex -shell-escape workshop_ad.tex
biber workshop_ad.bcf
pdflatex -shell-escape workshop_ad.tex
biber workshop_ad.bcf
