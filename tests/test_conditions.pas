var 
a,b: integer;
begin                     

a:=1;
b:=2;

if ((a+b)==(b+a)) then
begin
	println_string('ok');
end
else
begin
	println_string('wrong');
end;

if (a >= b) then println_string('bad');
if (b >= a) then println_string('good');

println_string('end');
end.
