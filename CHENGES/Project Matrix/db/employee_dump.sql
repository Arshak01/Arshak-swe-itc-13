--
-- PostgreSQL database dump
--

-- Dumped from database version 12.9 (Ubuntu 12.9-0ubuntu0.20.04.1)
-- Dumped by pg_dump version 12.9 (Ubuntu 12.9-0ubuntu0.20.04.1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: employee_data; Type: TABLE; Schema: public; Owner: angelamtvs
--

CREATE TABLE public.employee_data (
    employee_id integer NOT NULL,
    planned_rate double precision NOT NULL,
    month date NOT NULL,
    employee_name character varying(25),
    actual_rate real NOT NULL,
    position_id integer NOT NULL,
    status_id integer NOT NULL,
    hr_employee_data integer NOT NULL,
    branch_id integer NOT NULL,
    unit_id integer NOT NULL
);


ALTER TABLE public.employee_data OWNER TO angelamtvs;

--
-- Data for Name: employee_data; Type: TABLE DATA; Schema: public; Owner: angelamtvs
--

COPY public.employee_data (employee_id, planned_rate, month, employee_name, actual_rate, position_id, status_id, hr_employee_data, branch_id, unit_id) FROM stdin;
\.


--
-- Name: employee_data employee_data_pkey; Type: CONSTRAINT; Schema: public; Owner: angelamtvs
--

ALTER TABLE ONLY public.employee_data
    ADD CONSTRAINT employee_data_pkey PRIMARY KEY (employee_id);


--
-- PostgreSQL database dump complete
--

