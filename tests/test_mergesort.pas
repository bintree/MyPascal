procedure mergesort(from_index, to_index: integer);
var
b: array[0..100] of integer;
i, j, k, m: integer;
begin

if (from_index < to_index) then
begin
	m:=(from_index+to_index) div 2;
	mergesort(from_index, m);
	mergesort(m+1, to_index);
	i:=from_index; j:= m+1;
	k:=0;
	while ((i <= m) && (j <= to_index)) do
	begin
		if (a[i] < a[j]) then
		begin
			b[k]:=a[i];
			i:=i+1;
		end
		else 
		begin
			b[k]:=a[j];
			j:=j+1;
		end;
		k:=k+1;
	end;
	while (i <= m) do 
	begin
		b[k]:=a[i];
		i:=i+1;
		k:=k+1;
	end;
	while (j <= to_index) do 
	begin
		b[k]:=a[j];
		j:=j+1;
		k:=k+1;
	end;
	for i:=0 to k-1 do
		a[i+from_index]:=b[i];
end;

end;

var 
a: array[1..100] of integer;
i,n: integer;
begin

n:=10;
for i:=1 to n do a[i]:=400 - i*i*i mod 239;
println_string('before');
for i:=1 to n do println_integer(a[i]);

mergesort(1, n);

println_string('after');
for i:=1 to n do println_integer(a[i]);

end.