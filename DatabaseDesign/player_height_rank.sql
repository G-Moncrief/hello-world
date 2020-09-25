CREATE OR REPLACE FUNCTION player_height_rank(firstn VARCHAR, lastn VARCHAR)
RETURNS integer AS $$
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