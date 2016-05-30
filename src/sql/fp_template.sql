-- Table: fp_template

-- DROP TABLE fp_template;

CREATE TABLE fp_template
(
  verification_code character varying(4) NOT NULL,
  user_id character varying(30),
  creation_time character varying(36),
  last_operator character varying(10),
  last_update_time character varying(36),
  left_thumb character varying(2964),
  left_index character varying(2964),
  left_middle character varying(2964),
  left_ring character varying(2964),
  left_pinkie character varying(2964),
  right_thumb character varying(2964),
  right_index character varying(2964),
  right_middle character varying(2964),
  right_ring character varying(2964),
  right_pinkie character varying(2964),
  device_sn character varying(40),
  last_operator_name text,
  last_modified timestamp without time zone,
  CONSTRAINT pk_fp_template PRIMARY KEY (verification_code)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_template
  OWNER TO absensi;
GRANT ALL ON TABLE fp_template TO sclops;

-- Trigger: insert_last_modified on fp_template

-- DROP TRIGGER insert_last_modified ON fp_template;

CREATE TRIGGER insert_last_modified
  BEFORE UPDATE
  ON fp_template
  FOR EACH ROW
  EXECUTE PROCEDURE moddatetime('last_modified');

-- Trigger: insert_operator_name on fp_template

-- DROP TRIGGER insert_operator_name ON fp_template;

CREATE TRIGGER insert_operator_name
  BEFORE INSERT OR UPDATE
  ON fp_template
  FOR EACH ROW
  EXECUTE PROCEDURE insert_username('last_operator_name');

