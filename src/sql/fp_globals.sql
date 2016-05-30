-- Table: fp_globals

-- DROP TABLE fp_globals;

CREATE TABLE fp_globals
(
  id smallint NOT NULL,
  start_work time without time zone NOT NULL, -- start office hour
  end_work time without time zone NOT NULL, -- end office hour
  start_break time without time zone NOT NULL, -- start break time
  end_break time without time zone NOT NULL, -- end break time
  overtime_mode character varying(11) NOT NULL DEFAULT 'NO_OVERTIME'::character varying, -- default employee overtime mode
  office_location character varying(25) NOT NULL DEFAULT 'HEAD OFFICE'::character varying, -- default location
  in_greeting character varying(256) NOT NULL, -- default incoming greeting
  out_greeting character varying(256) NOT NULL, -- default out greeting
  maximum_try smallint NOT NULL DEFAULT 4, -- default maximum try to scan fingerprint
  last_operator_name text,
  last_modified timestamp without time zone DEFAULT now(),
  CONSTRAINT fp_globals_pkey PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_globals
  OWNER TO absensi;
COMMENT ON TABLE fp_globals
  IS 'this table stores default global values ';
COMMENT ON COLUMN fp_globals.start_work IS 'start office hour';
COMMENT ON COLUMN fp_globals.end_work IS 'end office hour';
COMMENT ON COLUMN fp_globals.start_break IS 'start break time';
COMMENT ON COLUMN fp_globals.end_break IS 'end break time';
COMMENT ON COLUMN fp_globals.overtime_mode IS 'default employee overtime mode';
COMMENT ON COLUMN fp_globals.office_location IS 'default location';
COMMENT ON COLUMN fp_globals.in_greeting IS 'default incoming greeting';
COMMENT ON COLUMN fp_globals.out_greeting IS 'default out greeting';
COMMENT ON COLUMN fp_globals.maximum_try IS 'default maximum try to scan fingerprint';


-- Trigger: insert_last_modified on fp_globals

-- DROP TRIGGER insert_last_modified ON fp_globals;

CREATE TRIGGER insert_last_modified
  BEFORE UPDATE
  ON fp_globals
  FOR EACH ROW
  EXECUTE PROCEDURE moddatetime('last_modified');

-- Trigger: insert_operator_name on fp_globals

-- DROP TRIGGER insert_operator_name ON fp_globals;

CREATE TRIGGER insert_operator_name
  BEFORE INSERT OR UPDATE
  ON fp_globals
  FOR EACH ROW
  EXECUTE PROCEDURE insert_username('last_operator_name');

