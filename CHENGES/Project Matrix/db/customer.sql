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
-- Name: customers; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.customers (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    address character varying(50),
    phone_number character varying(25),
    email character varying(50),
    info character varying(255)
);


ALTER TABLE public.customers OWNER TO postgres;

--
-- Name: customers_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.customers_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.customers_id_seq OWNER TO postgres;

--
-- Name: customers_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.customers_id_seq OWNED BY public.customers.id;


--
-- Name: customers id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.customers ALTER COLUMN id SET DEFAULT nextval('public.customers_id_seq'::regclass);


--
-- Data for Name: customers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.customers (id, name, address, phone_number, email, info) FROM stdin;
1	Adrianna Carter	uewwx	611-4372-56	a.carter@randatmail.com	lsjyvhkicb
2	Stella Jones	tmckl	172-7240-89	s.jones@randatmail.com	mjknuqvejh
3	George Hill	zfygd	610-6326-39	g.hill@randatmail.com	tcfhqseaaj
4	Adelaide Harris	edaug	716-2136-93	a.harris@randatmail.com	yuzuudjqmz
5	Derek Johnson	jcsty	651-7610-90	d.johnson@randatmail.com	dxrevaogej
6	Amy Edwards	ecvph	963-6145-16	a.edwards@randatmail.com	wlwqaqfjyj
7	Connie Morris	tmhym	362-9760-51	c.morris@randatmail.com	chhggdgxvm
8	Blake Johnston	ewoss	288-2628-04	b.johnston@randatmail.com	ibpckhilkl
9	Rubie Parker	mspkd	314-3278-30	r.parker@randatmail.com	vcidrbrmkn
10	Jacob Cooper	esrbt	885-7879-00	j.cooper@randatmail.com	ltdbbpnqvu
\.


--
-- Name: customers_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.customers_id_seq', 10, true);


--
-- Name: customers customers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.customers
    ADD CONSTRAINT customers_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

