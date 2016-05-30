-- Table: fp_operator

-- DROP TABLE fp_operator;

CREATE TABLE fp_operator
(
  id serial PRIMARY KEY,
  user_id character varying(10) NOT NULL,
  login_name character varying(15) NOT NULL,
  privileges_level integer NOT NULL,
  can_login boolean,
  last_operator_name text,
  last_modified timestamp without time zone
)
WITH (
  OIDS=FALSE
);
ALTER TABLE fp_operator
  OWNER TO absensi;
GRANT ALL ON TABLE fp_operator TO sclops;

-- Trigger: insert_last_modified on fp_operator

-- DROP TRIGGER insert_last_modified ON fp_operator;

CREATE TRIGGER insert_last_modified
  BEFORE UPDATE
  ON fp_operator
  FOR EACH ROW
  EXECUTE PROCEDURE moddatetime('last_modified');

-- Trigger: insert_operator_name on fp_operator

-- DROP TRIGGER insert_operator_name ON fp_operator;

CREATE TRIGGER insert_operator_name
  BEFORE INSERT OR UPDATE
  ON fp_operator
  FOR EACH ROW
  EXECUTE PROCEDURE insert_username('last_operator_name');

