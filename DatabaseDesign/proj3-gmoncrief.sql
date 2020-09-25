-- function 1 declaration

CREATE OR REPLACE FUNCTION fibonacci (lastN INTEGER) 
RETURNS int AS $$
DECLARE
    counter INTEGER := 1;
	a INTEGER := 0;
	b INTEGER := 1;
	res INTEGER := 0;   
BEGIN

IF lastN < 0 OR lastN > 1000
THEN RETURN -1;

ELSE
    IF lastN = 0
	THEN RETURN 0;
	
	ELSIF lastN = 1
	THEN RETURN 1;
	
	ELSE
    LOOP
	    res = a + b;
	    a = b;
	    b = res;
		counter := counter + 1;
	    EXIT WHEN counter = lastN;
	END LOOP;
	RETURN res;
	END IF;
END IF;
END;
$$ LANGUAGE plpgsql;

-- function 2 declaration

CREATE OR REPLACE FUNCTION player_height_rank (firstname VARCHAR, lastname VARCHAR) RETURNS int AS $$
DECLARE
	h_target FLOAT := 0.0;
	h_rank INTEGER := 1;
	r record;
	
BEGIN

SELECT DISTINCT INTO h_target (P.h_feet * 12 + P.h_inches)
FROM players AS P
WHERE P.firstname=$1 AND P.lastname=$2;

	FOR r IN SELECT DISTINCT (P.h_feet * 12 + P.h_inches) AS h_total
		FROM players AS P
		ORDER BY h_total DESC
		LOOP
			IF r.h_total > h_target THEN
				h_rank := h_rank + 1;
			ELSIF r.h_total = h_target THEN
				RETURN h_rank;
			ELSE
			    RETURN 0;
			END IF;
		END LOOP;	
END;
$$ LANGUAGE plpgsql;

