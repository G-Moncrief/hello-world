SELECT firstname, 
       lastname 
FROM   (SELECT firstname, 
               lastname, 
               cid, 
               Count(tid) AS teamcount 
        FROM   (SELECT DISTINCT firstname, 
                                lastname, 
                                tid, 
                                cid 
                FROM   coaches_season) AS bulkteamlist 
        GROUP  BY firstname, 
                  lastname, 
                  cid) AS teamcounter 
WHERE  teamcount = 2 
ORDER  BY lastname; 
-- P1:
-- Find all the coaches who have coached exactly TWO teams. List their first 
-- names followed by their last names.


SELECT DISTINCT BOSDENplayers.firstname 
FROM   (SELECT DISTINCT players.firstname, 
                        players.lastname, 
                        teams.location 
        FROM   players, 
               teams, 
               player_rs 
        WHERE  Upper(player_rs.ilkid) = Upper(players.ilkid) 
               AND Upper(player_rs.tid) = Upper(teams.tid) 
               AND ( teams.location = 'Boston' 
                      OR teams.location = 'Denver' ))AS BOSDENplayers; 
-- P2
-- Find all the players who played in a Boston team or a Denver team. List 
-- their first names only.


SELECT DISTINCT coaches_season.firstname, 
                coaches_season.lastname, 
                coaches_season.year, 
                teams.NAME 
FROM   coaches_season, 
       teams, 
       player_rs 
WHERE  Upper(coaches_season.cid) = Upper(player_rs.ilkid) 
       AND coaches_season.tid = teams.tid 
       AND player_rs.tid = teams.tid 
       AND player_rs.year = coaches_season.year 
ORDER  BY coaches_season.year; 
-- P3
-- Find those who were a coach and a player on the same team/same season
-- List their first names, last names, team, and year(s) this happened

SELECT NAME, 
       year, 
       Round (Cast(h_cm_avg AS NUMERIC), 4) AS h_cm_avg 
FROM   (SELECT PJ_teams.NAME, 
               player_rs.year, 
               Avg(( h_feet * 12 + h_inches ) * 2.54) AS h_cm_avg 
        FROM   player_rs, 
               players, 
               teams, 
               (SELECT teams.NAME, 
                       year, 
                       coaches_season.tid 
                FROM   coaches_season, 
                       teams 
                WHERE  teams.tid = coaches_season.tid 
                       AND coaches_season.cid = 'JACKSPH01') AS PJ_teams 
        WHERE  player_rs.year = PJ_teams.year 
               AND player_rs.tid = PJ_teams.tid 
               AND Upper(players.ilkid) = Upper(player_rs.ilkid) 
        GROUP  BY player_rs.year, 
                  PJ_teams.NAME) AS h_sum 
ORDER  BY h_cm_avg DESC; 

-- P4
-- Find avg height in cm of ea team coached by Phil Jackson sort by avg height
-- NOTE: using 1 inch = 2.54cm conversion, decimal places to 4 digits
-- ordered in DESC per sample.out

SELECT firstname, 
       lastname 
FROM   coaches_season 
       INNER JOIN (SELECT Count(ilkid) AS playercount, 
                          tid 
                   FROM   player_rs 
                   WHERE  year = 2003 
                   GROUP  BY tid) AS teams2003 
               ON teams2003.tid = coaches_season.tid 
WHERE  year = 2003 
       AND playercount = (SELECT Max(playercount) 
                          FROM   (SELECT Count(ilkid)AS playercount, 
                                         tid 
                                  FROM   player_rs 
                                  WHERE  tid = ANY (SELECT tid 
                                                    FROM   coaches_season 
                                                    WHERE  year = 2003) 
                                         AND year = 2003 
                                  GROUP  BY tid)AS findmaxpc); 
-- P5
-- Find the firstname and lastname of coach who coached largest number of players
-- in 2003

SELECT firstname, 
       lastname 
FROM   coaches_season 
       INNER JOIN teams 
               ON teams.tid = coaches_season.tid 
WHERE  league = 'A' 
INTERSECT 
SELECT firstname, 
       lastname 
FROM   coaches_season 
       INNER JOIN teams 
               ON teams.tid = coaches_season.tid 
WHERE  league = 'N';
-- P6
-- Find the coaches who coached in all leagues 

SELECT DISTINCT coaches_season.firstname, 
                coaches_season.lastname, 
                coaches_season.year, 
                teams.NAME 
FROM   coaches_season, 
       teams, 
       player_rs 
WHERE  Upper(coaches_season.cid) = Upper(player_rs.ilkid) 
       AND coaches_season.tid != teams.tid 
       AND player_rs.tid = teams.tid 
       AND player_rs.year = coaches_season.year 
ORDER  BY coaches_season.lastname; 
-- P7
-- Find those who were a coach and a player in the same season but on 
-- different teams

SELECT firstname, 
       lastname, 
       pts 
FROM   player_rs_career 
WHERE  pts > (SELECT pts 
              FROM   player_rs_career 
              WHERE  ilkid = 'JORDAMI01'); 
-- P8
-- Find players who scored more points than Michal Jordan

SELECT firstname, 
       lastname,
       success	   
FROM   (SELECT firstname, 
               lastname, 
               ( total_win / ( total_win + total_loss ) ) AS success 
        FROM   (SELECT firstname, 
                       lastname, 
                       Sum(season_win)  AS total_win, 
                       Sum(season_loss) AS total_loss 
                FROM  (SELECT firstname, 
                              lastname, 
                              year, 
                              season_win, 
                              season_loss 
                       FROM   coaches_season) AS temp 
                GROUP  BY firstname, 
                          lastname) AS temp2 
        GROUP  BY firstname, 
                  lastname, 
                  total_win, 
                  total_loss) AS temp3 
WHERE  success = (SELECT Max(success) 
                  FROM   (SELECT firstname, 
                                 lastname, 
                                 ( total_win / ( total_win + total_loss ) ) AS success 
                          FROM   (SELECT firstname, 
                                         lastname, 
                                         Sum(season_win)  AS total_win, 
                                         Sum(season_loss) AS total_loss 
                                  FROM  (SELECT firstname, 
                                                lastname, 
                                                year, 
                                                season_win, 
                                                season_loss 
                                         FROM   coaches_season) AS temp 
                                  GROUP  BY firstname, 
                                            lastname) AS temp2)AS maxfind); 
-- P9
-- Find most successful coached based on season_win/(season_win + season_loss)

SELECT DISTINCT draft.draft_from, 
                draftcount 
FROM   draft 
       INNER JOIN (SELECT draft_from, 
                          Count(draft_from) AS draftcount 
                   FROM   draft 
                   GROUP  BY draft_from) AS draftcounter 
               ON draftcounter.draft_from = draft.draft_from 
WHERE  draftcount = (SELECT Max(draftcount) 
                     FROM   (SELECT DISTINCT draft.draft_from, 
                                             draftcount 
                             FROM   draft 
                                    INNER JOIN (SELECT draft_from, 
                                                       Count(draft_from) AS draftcount 
                                                FROM   draft 
                                                GROUP  BY draft_from) AS draftcounter 
                                            ON 
                                    draftcounter.draft_from = draft.draft_from 
                             WHERE  draftcount < (SELECT Max(draftcount) 
                                                  FROM 
                                    (SELECT DISTINCT draft.draft_from, 
                                                     draftcount 
                                     FROM   draft 
                                            INNER JOIN (SELECT 
                                            draft_from, 
                                            Count(draft_from) AS draftcount 
                                                        FROM   draft 
                                                        GROUP  BY draft_from) 
                                                       AS draftcounter 
                                                    ON 
                                            draftcounter.draft_from = draft.draft_from) 
                                    AS 
                                    maxcount))AS secondmaxcount); 
-- P10
-- Find school with second largest number of drafts
-- NOTE: for this I used the draft_from field and the count I return for Kentucky
-- matches up with the count of SELECT DISTINCT * FROM draft WHERE draft_from='Kentucky';