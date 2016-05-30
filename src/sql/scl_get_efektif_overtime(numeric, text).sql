-- Function: scl_get_efektif_overtime(numeric, text)

-- DROP FUNCTION scl_get_efektif_overtime(numeric, text);

CREATE OR REPLACE FUNCTION scl_get_efektif_overtime(
    numeric,
    text)
  RETURNS numeric AS
$BODY$
DECLARE

   pOT                       ALIAS FOR $1;
   pRemark                   ALIAS FOR $2;
   pResult		     numeric;
   pTmpResult		     numeric;
   pMul			     numeric;
   pI			     integer;
   pOT_trunc                 numeric;
   pCmd                      text;
   pDay                      text;

BEGIN

   pResult    = 0;
   pTmpResult = 0;
   pMul       = 0;
   pI	      = 0;
   pOT_trunc  = 0;
   pCmd       = '';
   pDay       = '';

   -- truncate commas ( ex: 3.3 become 3)
   pOT_trunc  = trunc(pOT );
   -- get day key
   pDay       = (SELECT quote_ident(pRemark));

   -- for every hour, add overtime rate to pTmpResult
   FOR i IN 1..pOT_trunc LOOP
      pCmd       = 'SELECT ' || pDay || ' FROM fp_ot_defs WHERE hours = ' || to_char(i,'99');
      EXECUTE  pCmd INTO pMul;

      IF pMul ISNULL THEN
         pCmd       = 'SELECT MAX(' || pDay || ') FROM fp_ot_defs';
      END IF;

      EXECUTE  pCmd INTO pMul;

      pTmpResult = 1*pMul;
      pResult = pResult+pTmpResult;
      -- increase pI, so we have last hour we have add
      pI=pI+1;

   END LOOP;

   -- for overtime which bigger than pI ( eg.a case where overtime is 3.5 hour, will have pI as 3, thus we need to
   -- count 0.5 left, which we get value from 4
   IF (pOT-pI) > 0 THEN
      pCmd       = 'SELECT ' || pDay || ' FROM fp_ot_defs WHERE hours = ' || to_char((pI+1),'99');
      EXECUTE  pCmd INTO pMul;

      IF pMul ISNULL THEN
         pCmd       = 'SELECT MAX(' || pDay || ') FROM fp_ot_defs';
      END IF;

      EXECUTE  pCmd INTO pMul;
      pResult = pResult + ((pOT-pI)*pMul);

   END IF;
      
   RETURN pResult;

END;$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100;
ALTER FUNCTION scl_get_efektif_overtime(numeric, text)
  OWNER TO absensi;
COMMENT ON FUNCTION scl_get_efektif_overtime(numeric, text) IS 'Calculcates efektif overtime';
