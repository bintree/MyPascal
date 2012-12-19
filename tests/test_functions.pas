function f(a: integer):integer;
var
b: array[1..2] of integer;
begin
b[1]:=a;
b[2]:=b[1]*a;
result:=b[2]+b[1];
end;
procedure print_square(a: integer);
begin
println_integer(a*a);
end;
var 
b: integer;
begin                     
b:=5;
println_integer(f(b));

print_square(5);

end.
