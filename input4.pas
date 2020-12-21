program ThirdExample;
var
x, result: integer;
str1: string;

begin

	write("Hello world!");
	write("Let's calculate a factorial!");
	write("Enter the integer number:");
	
	read(x); 
	
	write("The factorial is:");
	
	if (x < 2) then
	    begin
		    write(1);
		    write("The result was calculated in the false branch.");
		end;
	else begin
		result := 1;
		while (x >= 2) do
	       	begin
			result := result * x;
			x := x - 1;	
		end;
		write(result);
		write("The result was calculated in the false branch.");
	end;
	
	write("Now enter a string to test how interpreter deals with it.");
	read(str1);

	write("Interpreter can only read and print strings, thus, it will remind you of what you have just wrote:");
	
	write(str1);
	
	write("Thank you, bye!");
	
end.

