-- Function: scl_interval_to_numeric(interval)

-- DROP FUNCTION scl_interval_to_numeric(interval);

CREATE OR REPLACE FUNCTION scl_interval_to_numeric(interval)
  RETURNS numeric AS
$BODY$
DECLARE

   pInterval          ALIAS FOR $1;
   pResult            numeric(4,2);
   pHour              numeric;
   pMinute            numeric;
   pSecond            numeric;
   pIntervalStr       text;

BEGIN

   pResult   = 0;
   pHour     = 0;
   pMinute   = 0;
   pSecond   = 0;

   BEGIN
      --pIntervalStr = (SELECT to_char(pInterval,'HH24:MI:SS'));
      pHour   = EXTRACT('HOUR' FROM pInterval );
      pMinute = EXTRACT('MINUTE' FROM pInterval );
      pSecond = EXTRACT('SECOND' FROM pInterval );
      pResult = pHour + (pMinute/60);

   END;
   RETURN pResult;
END;$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100;
ALTER FUNCTION scl_interval_to_numeric(interval)
  OWNER TO absensi;
COMMENT ON FUNCTION scl_interval_to_numeric(interval) IS 'convert time interval to numeric';
