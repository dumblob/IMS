set terminal png size 1000,1100

set output 'exp1.png'
#set size 1.0,0.5
#set border 3

set multiplot layout 3,1 columnsfirst
set nokey

set title "Zavislost delky zpracovani objednavky na poctu objednanych reklam"
set xlabel "pocet reklam BOSE"
set ylabel "minuty"
#set size 0.5,0.5
#set origin 0,0
plot "exp1a.dat" smooth unique

set title "Zavislost prumerneho casu zpracovani jedne objednavky na delce behu vyroby"
set xlabel "minuty (krok 3 mesice)"
set ylabel "minuty"
plot "exp1b.dat" smooth bezier

set title "Prumerna doba, kterou objednavka stravi v jednotlivych zarizenich"
#set boxwidth 0.5
set xlabel "% z celkove doby"
unset ylabel
set style fill solid
plot "exp1c.dat" using 1:3:xtic(2) with boxes
#data.dat:
#0 label       100
#1 label2      450
#2 "bar label" 75

unset multiplot

# vim: set ft=gnuplot:
