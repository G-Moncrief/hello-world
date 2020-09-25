CREATE OR REPLACE FUNCTION fibonacci(i INTEGER) 
RETURNS NUMERIC AS $$

DECLARE
    counter INTEGER := 1;
	a NUMERIC := 0;
	b NUMERIC := 1;
	res NUMERIC := 0;
	
BEGIN

IF i < 0 OR i > 1000
THEN RETURN -1;

ELSE

    IF i = 0
	THEN RETURN 0;
	
	ELSIF i = 1
	THEN RETURN 1;
	
	ELSE
    LOOP

	    res = a + b;
	    a = b;
	    b = res;
		counter := counter + 1;
	    EXIT WHEN counter = i;
	END LOOP;
	
	RETURN res;

	END IF;
	
END IF;

END;

$$ LANGUAGE plpgsql;