-- Table: fp_logger

-- DROP TABLE fp_logger;

CREATE TABLE fp_logger
(
  log_id serial PRIMARY KEY ,
  log_date character varying(20),
  log_day character varying(20),
  log_time character varying(20),
  user_name character varying(30),
  log_type character varying(20),
  log_message character varying(512)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_logger
  OWNER TO absensi;
GRANT ALL ON TABLE fp_logger TO sclops;
GRANT SELECT, UPDATE, INSERT ON TABLE fp_logger TO public;
