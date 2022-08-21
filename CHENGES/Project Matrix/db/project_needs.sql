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
-- Name: project_needs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.project_needs (
    id integer NOT NULL,
    project_id integer DEFAULT 0 NOT NULL,
    amount integer DEFAULT 0,
    request_resource_name_id integer DEFAULT 0,
    unit_id integer DEFAULT 0,
    file_link character varying(50) DEFAULT 0,
    employee_count_change integer DEFAULT 0 NOT NULL,
    start_date date DEFAULT now() NOT NULL,
    end_date date
);


ALTER TABLE public.project_needs OWNER TO postgres;

--
-- Name: project_needs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.project_needs_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.project_needs_id_seq OWNER TO postgres;

--
-- Name: project_needs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.project_needs_id_seq OWNED BY public.project_needs.id;


--
-- Name: project_needs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.project_needs ALTER COLUMN id SET DEFAULT nextval('public.project_needs_id_seq'::regclass);


--
-- Data for Name: project_needs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.project_needs (id, project_id, amount, request_resource_name_id, unit_id, file_link, employee_count_change, start_date, end_date) FROM stdin;
1	1	2	9	3	doc_1_file.csv	17	2022-05-10	2023-08-18
2	2	17	1	4	doc_2_file.csv	18	2022-05-10	2023-11-21
3	3	3	10	16	doc_3_file.csv	17	2022-05-10	2022-11-26
4	4	4	3	9	doc_4_file.csv	5	2022-05-10	2023-03-06
5	5	14	9	4	doc_5_file.csv	9	2022-05-10	2023-03-21
6	6	11	6	11	doc_6_file.csv	5	2022-05-10	2023-08-28
7	7	14	10	3	doc_7_file.csv	8	2022-05-10	2023-01-25
8	8	17	2	11	doc_8_file.csv	11	2022-05-10	2022-10-22
9	9	28	8	13	doc_9_file.csv	20	2022-05-10	2022-10-22
10	10	15	2	9	doc_10_file.csv	21	2022-05-10	2023-11-26
11	11	11	8	20	doc_11_file.csv	10	2022-05-10	2023-08-28
12	12	10	6	16	doc_12_file.csv	9	2022-05-10	2023-12-06
13	13	16	9	5	doc_13_file.csv	16	2022-05-10	2023-08-03
14	14	20	8	2	doc_14_file.csv	10	2022-05-10	2023-05-15
15	15	19	10	20	doc_15_file.csv	20	2022-05-10	2023-01-20
16	16	14	10	8	doc_16_file.csv	6	2022-05-10	2023-11-01
17	17	8	6	13	doc_17_file.csv	10	2022-05-10	2022-05-15
18	18	12	8	5	doc_18_file.csv	5	2022-05-10	2023-04-05
19	19	11	2	14	doc_19_file.csv	11	2022-05-10	2022-10-22
20	20	10	8	9	doc_20_file.csv	9	2022-05-10	2022-10-22
21	21	28	6	18	doc_21_file.csv	18	2022-05-10	2023-07-14
22	22	26	8	17	doc_22_file.csv	12	2022-05-10	2023-01-20
23	23	30	3	3	doc_23_file.csv	10	2022-05-10	2022-12-21
24	24	8	4	15	doc_24_file.csv	4	2022-05-10	2022-05-30
25	25	6	9	3	doc_25_file.csv	12	2022-05-10	2023-05-30
26	26	14	6	1	doc_26_file.csv	13	2022-05-10	2022-08-08
27	27	11	5	8	doc_27_file.csv	5	2022-05-10	2023-10-07
28	28	21	3	16	doc_28_file.csv	16	2022-05-10	2022-12-16
29	29	16	4	10	doc_29_file.csv	8	2022-05-10	2022-08-03
30	30	22	6	4	doc_30_file.csv	18	2022-05-10	2022-08-13
31	31	4	2	7	doc_31_file.csv	21	2022-05-10	2022-05-10
32	32	11	1	20	doc_32_file.csv	13	2022-05-10	2023-04-15
33	33	23	6	14	doc_33_file.csv	2	2022-05-10	2022-08-13
34	34	12	9	3	doc_34_file.csv	7	2022-05-10	2023-04-25
35	35	2	2	1	doc_35_file.csv	12	2022-05-10	2022-12-11
36	36	13	6	13	doc_36_file.csv	9	2022-05-10	2023-07-09
37	37	13	2	2	doc_37_file.csv	10	2022-05-10	2023-10-07
38	38	26	10	20	doc_38_file.csv	8	2022-05-10	2022-07-14
39	39	28	1	18	doc_39_file.csv	11	2022-05-10	2023-12-01
40	40	21	10	5	doc_40_file.csv	5	2022-05-10	2022-11-06
41	41	16	6	3	doc_41_file.csv	9	2022-05-10	2022-09-27
42	42	23	6	16	doc_42_file.csv	3	2022-05-10	2023-08-18
43	43	10	9	3	doc_43_file.csv	18	2022-05-10	2023-05-30
44	44	7	6	1	doc_44_file.csv	2	2022-05-10	2023-12-26
45	45	11	1	18	doc_45_file.csv	13	2022-05-10	2023-06-09
46	46	17	5	2	doc_46_file.csv	11	2022-05-10	2022-10-22
47	47	9	4	15	doc_47_file.csv	11	2022-05-10	2023-10-12
48	48	21	5	10	doc_48_file.csv	20	2022-05-10	2022-11-26
49	49	9	8	6	doc_49_file.csv	15	2022-05-10	2023-06-19
50	50	3	10	5	doc_50_file.csv	21	2022-05-10	2023-10-27
51	51	12	7	17	doc_51_file.csv	18	2022-05-10	2022-08-18
52	52	9	6	7	doc_52_file.csv	12	2022-05-10	2023-06-24
53	53	4	3	10	doc_53_file.csv	19	2022-05-10	2022-11-26
54	54	24	5	9	doc_54_file.csv	16	2022-05-10	2023-10-07
55	55	11	5	3	doc_55_file.csv	21	2022-05-10	2022-12-01
56	56	27	2	4	doc_56_file.csv	10	2022-05-10	2022-11-21
57	57	26	4	10	doc_57_file.csv	21	2022-05-10	2023-07-29
58	58	26	10	20	doc_58_file.csv	15	2022-05-10	2022-11-01
59	59	2	9	16	doc_59_file.csv	9	2022-05-10	2023-02-24
60	60	14	7	12	doc_60_file.csv	18	2022-05-10	2023-02-19
61	61	2	4	7	doc_61_file.csv	7	2022-05-10	2023-08-03
62	62	22	8	12	doc_62_file.csv	15	2022-05-10	2022-11-16
63	63	16	1	20	doc_63_file.csv	14	2022-05-10	2023-03-11
64	64	15	2	4	doc_64_file.csv	13	2022-05-10	2023-04-15
65	65	1	1	6	doc_65_file.csv	8	2022-05-10	2022-10-02
66	66	29	9	18	doc_66_file.csv	9	2022-05-10	2023-09-17
67	67	26	2	12	doc_67_file.csv	17	2022-05-10	2023-07-29
68	68	27	7	2	doc_68_file.csv	14	2022-05-10	2023-04-05
69	69	23	8	6	doc_69_file.csv	6	2022-05-10	2023-11-26
70	70	14	3	12	doc_70_file.csv	11	2022-05-10	2023-06-09
71	71	9	1	20	doc_71_file.csv	2	2022-05-10	2023-01-25
72	72	28	9	6	doc_72_file.csv	11	2022-05-10	2022-08-08
73	73	18	8	8	doc_73_file.csv	13	2022-05-10	2023-01-30
74	74	14	5	1	doc_74_file.csv	17	2022-05-10	2022-12-31
75	75	7	6	17	doc_75_file.csv	20	2022-05-10	2022-11-16
76	76	11	2	9	doc_76_file.csv	4	2022-05-10	2022-11-06
77	77	7	3	7	doc_77_file.csv	8	2022-05-10	2023-04-10
78	78	3	4	13	doc_78_file.csv	6	2022-05-10	2022-05-10
79	79	20	7	2	doc_79_file.csv	12	2022-05-10	2023-07-04
80	80	12	1	3	doc_80_file.csv	20	2022-05-10	2023-08-13
\.


--
-- Name: project_needs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.project_needs_id_seq', 80, true);


--
-- Name: id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX id ON public.project_needs USING btree (id);


--
-- PostgreSQL database dump complete
--
