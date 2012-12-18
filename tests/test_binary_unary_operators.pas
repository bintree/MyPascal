var 
a,b,c: integer;
d,e,f: double;
x,y: string;
begin
a:=2;
b:=2;
c:=2*2;
println_integer(c);
println_integer( (a+b) div 2 * 5 + 1 mod 2 * 3 );
println_integer( ((a+b) div 2 * 5 + 1 mod 2 * 3) == 13 );
d:=6.0;
e:=7.0;

println_double(d/e*7.8);

println_integer((d/e*7.8 > 6.68) && ((d/e*e - d) < 0.00000001) && ((d/e*e - d) > -0.00000001));
x:='abc';
y:=x+'def';
println_string(y);
end.
