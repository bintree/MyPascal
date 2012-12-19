var 
i,j: integer;
begin                     

for i:=1 to 2 do
	for j:=1 to 2 do
	begin
		println_integer(i);
		println_integer(j);
	end;

i:=0;
j:=0;

while ((i + j) < 20) do
begin
	println_integer(i);
	println_integer(j);
	i:=j*j;
	j:=i+1;
end;


end.
