-- Table: fp_karyawan

-- DROP TABLE fp_karyawan;

CREATE TABLE fp_karyawan
(
  user_id character varying(30) NOT NULL,
  user_name character varying(30) NOT NULL,
  user_password character varying(35), -- password , optional
  start_work_hour time without time zone,
  end_work_hour time without time zone,
  in_greeting character varying(255),
  out_greeting character varying(255),
  creation_time character varying(36),
  last_update_time character varying(36),
  last_operator character varying(20),
  overtime_mode character varying(20) DEFAULT 'NO_OVERTIME'::character varying,
  m_id smallint NOT NULL DEFAULT (-1), -- HMTAS Fingerprint device user ID
  last_operator_name text,
  last_modified timestamp without time zone DEFAULT now(),
  max_ot interval, -- maximum overtime allowed
  loc_id integer NOT NULL DEFAULT 1, -- location indentifier for employee
  active boolean NOT NULL DEFAULT true,
  mon_start_ot time without time zone NOT NULL DEFAULT '17:30:00'::time without time zone, -- time to start overtime count in monday
  tue_start_ot time without time zone NOT NULL DEFAULT '17:30:00'::time without time zone, -- time to start overtime count in tuesday
  wed_start_ot time without time zone NOT NULL DEFAULT '17:30:00'::time without time zone, -- time to start overtime count in wednesday
  thu_start_ot time without time zone NOT NULL DEFAULT '17:30:00'::time without time zone, -- time to start overtime count in thursday
  fri_start_ot time without time zone NOT NULL DEFAULT '17:30:00'::time without time zone, -- time to start overtime count in friday
  sat_start_ot time without time zone NOT NULL DEFAULT '17:30:00'::time without time zone, -- time to start overtime count in saturday
  sun_start_ot time without time zone NOT NULL DEFAULT '00:00:00'::time without time zone, -- time to start overtime count in sunday
  CONSTRAINT fp_karyawan_pkey PRIMARY KEY (user_id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_karyawan
  OWNER TO absensi;
COMMENT ON TABLE fp_karyawan
  IS 'table ini menyimpan data karyawan  ( basic )';
COMMENT ON COLUMN fp_karyawan.user_password IS 'password , optional';
COMMENT ON COLUMN fp_karyawan.m_id IS 'HMTAS Fingerprint device user ID';
COMMENT ON COLUMN fp_karyawan.max_ot IS 'maximum overtime allowed';
COMMENT ON COLUMN fp_karyawan.loc_id IS 'location indentifier for employee';
COMMENT ON COLUMN fp_karyawan.mon_start_ot IS 'time to start overtime count in monday';
COMMENT ON COLUMN fp_karyawan.tue_start_ot IS 'time to start overtime count in tuesday';
COMMENT ON COLUMN fp_karyawan.wed_start_ot IS 'time to start overtime count in wednesday';
COMMENT ON COLUMN fp_karyawan.thu_start_ot IS 'time to start overtime count in thursday';
COMMENT ON COLUMN fp_karyawan.fri_start_ot IS 'time to start overtime count in friday';
COMMENT ON COLUMN fp_karyawan.sat_start_ot IS 'time to start overtime count in saturday';
COMMENT ON COLUMN fp_karyawan.sun_start_ot IS 'time to start overtime count in sunday';


-- Trigger: insert_last_modified on fp_karyawan

-- DROP TRIGGER insert_last_modified ON fp_karyawan;

CREATE TRIGGER insert_last_modified
  BEFORE UPDATE
  ON fp_karyawan
  FOR EACH ROW
  EXECUTE PROCEDURE moddatetime('last_modified');

-- Trigger: insert_operator_name on fp_karyawan

-- DROP TRIGGER insert_operator_name ON fp_karyawan;

CREATE TRIGGER insert_operator_name
  BEFORE INSERT OR UPDATE
  ON fp_karyawan
  FOR EACH ROW
  EXECUTE PROCEDURE insert_username('last_operator_name');

