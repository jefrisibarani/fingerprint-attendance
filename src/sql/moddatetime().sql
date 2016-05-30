-- Function: moddatetime()

-- DROP FUNCTION moddatetime();

CREATE OR REPLACE FUNCTION moddatetime()
  RETURNS trigger AS
'$libdir/moddatetime', 'moddatetime'
  LANGUAGE c VOLATILE
  COST 1;
ALTER FUNCTION moddatetime()
  OWNER TO postgres;
