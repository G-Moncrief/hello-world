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



