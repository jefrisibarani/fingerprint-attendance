-- Table: "fp_absen_20090630"

-- DROP TABLE "fp_absen_20090630";

CREATE TABLE "fp_absen_20090630"
(
  id serial PRIMARY KEY ,
  m_day character varying(20),
  m_date date,
  in_time time without time zone,
  out_time time without time zone,
  overtime interval,
  overtime_int numeric(5,2),
  overtime_efektif numeric(5,2),
  remark character varying(20)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE "fp_absen_20090630"
  OWNER TO absensi;
COMMENT ON TABLE "fp_absen_20090630"
  IS 'absen table for Jhon';
