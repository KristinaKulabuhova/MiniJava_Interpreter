program WhileTest;
var
  b, sum: integer;

begin
  b := 1;
  sum := 0;
  while b <= 10 do
  begin
    sum := sum + b*b*b;
    b := b + 1;
  end;
  write(sum);
end.
