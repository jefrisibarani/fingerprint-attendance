-- Function: scl_calculate_overtime(text, date, date)

-- DROP FUNCTION scl_calculate_overtime(text, date, date);

CREATE OR REPLACE FUNCTION scl_calculate_overtime(
    text,
    date,
    date)
  RETURNS integer AS
$BODY$
DECLARE

   pUserID                   ALIAS FOR $1;
   pStartDate                ALIAS FOR $2;
   pEndDate                  ALIAS FOR $3;
   pBaseTableName            text;
   pEmpTableName             text;
   pSql                      text;
   pSqlUpdat                 text;
   pOT                       interval;
   pDat                      RECORD;
   maxot           	     interval;	

BEGIN

   pBaseTableName = 'fp_absen_';
   pEmpTableName  = pBaseTableName || pUserID;
   pSql           = ''; 
   pSqlUpdat      = '';
   pOT            = '00:00:00'::interval;
   maxot          = '00:00:00'::interval;
   BEGIN
   ----------------------------------------------------------------------------------------------------
   ----------------------------------------------------------------------------------------------------
      -- Update column "remark"
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('mon') 
         || ' WHERE m_day = ' || quote_literal('Monday')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  
      
      -- Update column "remark"
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('tue') 
         || ' WHERE m_day = ' || quote_literal('Tuesday')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

      -- Update column "remark"
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('wed') 
         || ' WHERE m_day = ' || quote_literal('Wednesday')   
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';
	   
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('thu') 
         || ' WHERE m_day = ' || quote_literal('Thursday')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

      -- Update column "remark"
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('fri') 
         || ' WHERE m_day = ' || quote_literal('Friday')   
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  
      
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('sat') 
         || ' WHERE m_day = ' || quote_literal('Saturday')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

      -- Update column "remark"
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('sun') 
         || ' WHERE m_day = ' || quote_literal('Sunday')   
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

      -- Update column "remark"
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('ph') 
         || ' WHERE EXISTS(SELECT 1 FROM fp_public_holiday p WHERE p.date = m_date::date)'
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

      -- Update column "remark"
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('ph_sat') 
         || ' WHERE EXISTS(SELECT 1 FROM fp_public_holiday p WHERE p.date = m_date::date)'
         || ' AND m_day = ' || quote_literal('Saturday')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

      -- Update column "remark"
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)    
         || ' SET remark = ' || quote_literal('ph_sun') 
         || ' WHERE EXISTS(SELECT 1 FROM fp_public_holiday p WHERE p.date = m_date::date)'
         || ' AND m_day = ' || quote_literal('Sunday')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  
	 
   ----------------------------------------------------------------------------------------------------

      -- process Sat,Sun and Public Holiday
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)
         || ' SET overtime = out_time::time - in_time::time'
         || ' WHERE (m_day IN (' || quote_literal('Saturday') || ',' || quote_literal('Sunday') || ')'
         || ' OR EXISTS (SELECT 1 FROM fp_public_holiday WHERE date = m_date::date))'
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

      -- process Mon,Tue,Wed,Thu,Fri and NOT Public Holiday for employee whose Overtime mode AFTER_8
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)
         || ' SET overtime = out_time::time - ' || quote_literal('08:00:00') || ' - ' || quote_literal('09:00:00') || '::interval'
         || ' WHERE m_day NOT IN (' || quote_literal('Saturday') || ',' || quote_literal('Sunday') || ')'
         || ' AND NOT EXISTS (SELECT 1 FROM fp_public_holiday WHERE date = m_date::date)'
         || ' AND (SELECT overtime_mode FROM fp_karyawan WHERE user_id = ' || quote_literal(pUserID) || ' )  = ' || quote_literal('AFTER_8')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) ||'::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) ||'::date;';


      -- process Mon,Tue,Wed,Thu,Fri and NOT Public Holiday for employee whose Overtime mode BEFORE_8
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)
         || ' SET overtime = out_time::time - in_time::time - '|| quote_literal('09:00:00') || '::interval'
         || ' WHERE m_day NOT IN (' || quote_literal('Saturday') || ',' || quote_literal('Sunday') || ')'
         || ' AND NOT EXISTS (SELECT 1 FROM fp_public_holiday WHERE date = m_date::date)'
         || ' AND (SELECT overtime_mode FROM fp_karyawan WHERE user_id = ' || quote_literal(pUserID) || ' )  = ' ||quote_literal('BEFORE_8')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) ||'::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) ||'::date;';  


      -- if employee has maximum_ot > 0 set in his table, check for it and apply
      pSql = 'SELECT max_ot FROM fp_karyawan WHERE user_id=' || quote_literal(pUserID);
      EXECUTE pSql INTO maxot;
      IF maxot > '00:00:00'::interval THEN
      
         EXECUTE 'UPDATE ' 
            || quote_ident(pEmpTableName)
            || ' SET overtime = '  || quote_literal(CAST(maxot AS text)) || '::interval'
            || ' WHERE overtime > '|| quote_literal(CAST(maxot AS text)) || '::interval'
            || ' AND m_date::date BETWEEN '
            || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) ||'::date AND '
	    || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) ||'::date;';  

      END IF;

      -- if overtime less than 30 minutes OR employee status is NO_OVERTIME, set overtime 0
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)
         || ' SET overtime = '||quote_literal('00:00:00') || '::interval'
         || ' WHERE overtime < '||quote_literal('00:30:00')|| '::interval'
         || ' OR (SELECT overtime_mode FROM fp_karyawan WHERE user_id = ' || quote_literal(pUserID) || ' ) = ' || quote_literal('NO_OVERTIME')
         || ' AND m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) ||'::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) ||'::date;';  

   ----------------------------------------------------------------------------------------------------

   

      -- process overtime integer
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)
         || ' SET overtime_int = scl_interval_to_numeric(overtime)'
         || ' WHERE m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

      -- process overtime efektif
      EXECUTE 'UPDATE ' 
         || quote_ident(pEmpTableName)
         || ' SET overtime_efektif = scl_get_efektif_overtime(overtime_int,remark)'
         || ' WHERE m_date::date BETWEEN '
         || quote_literal(to_char(pStartDate, 'YYYY-MM-DD')) || '::date AND '
	 || quote_literal(to_char(pEndDate,   'YYYY-MM-DD')) || '::date;';  

   
   ----------------------------------------------------------------------------------------------------
   
   END;
   RETURN 1;
END;$BODY$
  LANGUAGE plpgsql VOLATILE
  COST 100;
ALTER FUNCTION scl_calculate_overtime(text, date, date)
  OWNER TO absensi;
COMMENT ON FUNCTION scl_calculate_overtime(text, date, date) IS 'Calculcates employee overtime';
