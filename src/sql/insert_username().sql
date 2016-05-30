-- Function: insert_username()

-- DROP FUNCTION insert_username();

CREATE OR REPLACE FUNCTION insert_username()
  RETURNS trigger AS
'$libdir/insert_username', 'insert_username'
  LANGUAGE c VOLATILE
  COST 1;
ALTER FUNCTION insert_username()
  OWNER TO postgres;
