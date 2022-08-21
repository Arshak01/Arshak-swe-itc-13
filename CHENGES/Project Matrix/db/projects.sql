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
-- Name: projects; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.projects (
    project_id integer NOT NULL,
    project_name character varying(50) NOT NULL,
    role_id integer NOT NULL,
    customer_id integer NOT NULL,
    agent_id integer,
    engagement_category_id integer NOT NULL,
    engagement_model_id integer NOT NULL,
    country_id integer,
    start_date date NOT NULL,
    end_date date,
    budget character varying(25),
    confidential_type character varying(25),
    is_active boolean,
    achivements_report boolean,
    technology_tools character varying(255),
    about_project character varying(255)
);


ALTER TABLE public.projects OWNER TO postgres;

--
-- Name: projects_project_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.projects_project_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.projects_project_id_seq OWNER TO postgres;

--
-- Name: projects_project_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.projects_project_id_seq OWNED BY public.projects.project_id;


--
-- Name: projects project_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.projects ALTER COLUMN project_id SET DEFAULT nextval('public.projects_project_id_seq'::regclass);


--
-- Data for Name: projects; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.projects (project_id, project_name, role_id, customer_id, agent_id, engagement_category_id, engagement_model_id, country_id, start_date, end_date, budget, confidential_type, is_active, achivements_report, technology_tools, about_project) FROM stdin;
1	Web/Mobile	2	7	3	2	9	145	2022-06-28	2022-12-01	$61,913	Strictly Private	f	t	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur	Lorem ipsum dolor sit amet, consectetuer
2	Web/Mobile	8	39	19	9	3	156	2021-03-08	2021-12-28	$16,996	Strictly Private	t	f	Lorem ipsum dolor sit amet, consectetuer	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur sed
3	Webtrends Optimize	28	23	1	8	5	113	2021-06-15	2022-09-11	$77,908	On Request	t	f	Lorem ipsum dolor sit amet, consectetuer	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
4	Web/Mobile	3	46	18	3	5	69	2021-01-10	2023-03-18	$69,452	Standard	t	t	Lorem ipsum dolor sit amet, consectetuer	Lorem ipsum dolor sit amet, consectetuer
5	Bodn FQA	8	8	5	9	9	103	2020-04-01	2021-03-13	$86,202	On Request	f	t	Lorem ipsum dolor sit amet, consectetuer	Lorem ipsum dolor sit amet,
6	Webtrends Optimize	18	34	6	9	8	106	2020-02-17	2021-04-06	$36,466	Standard	t	f	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur
7	Webtrends Optimize	27	13	10	8	3	98	2021-09-11	2022-04-17	$87,784	Strictly Private	f	t	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.	Lorem ipsum dolor sit amet, consectetuer
8	Bodn FQA	8	7	14	4	1	95	2021-01-30	2022-03-24	$41,778	Strictly Private	f	t	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.	Lorem ipsum dolor sit amet, consectetuer
9	Webtrends Optimize	7	26	17	4	6	47	2022-10-09	2023-03-31	$29,510	Standard	t	f	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
10	Webtrends Optimize	19	43	18	10	5	169	2020-10-09	2022-04-10	$27,612	Strictly Private	f	f	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur
11	Bodn FQA	11	5	13	9	6	32	2020-03-23	2020-11-14	$26,130	On Request	f	f	Lorem ipsum dolor sit amet, consectetuer adipiscing	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur
12	Bodn FQA	9	57	7	6	6	22	2020-08-21	2022-02-19	$65,435	Standard	f	f	Lorem ipsum dolor sit amet, consectetuer	Lorem ipsum dolor sit amet, consectetuer
13	Web/Mobile	1	1	16	9	3	61	2023-03-02	2020-11-06	$61,028	Standard	t	f	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur	Lorem ipsum dolor sit amet, consectetuer
14	Web/Mobile	10	15	12	8	9	30	2021-06-06	2021-12-13	$13,780	On Request	t	f	Lorem ipsum dolor sit amet, consectetuer	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur
15	Bodn FQA	24	33	14	7	8	46	2020-05-06	2020-03-17	$20,069	On Request	t	f	Lorem ipsum dolor sit amet, consectetuer adipiscing	Lorem ipsum dolor sit amet, consectetuer adipiscing
16	Web/Mobile	15	10	19	5	8	96	2020-05-20	2023-02-09	$98,148	On Request	f	t	Lorem ipsum dolor sit amet,	Lorem ipsum dolor sit amet, consectetuer adipiscing
17	Web/Mobile	3	32	1	6	6	40	2022-08-30	2020-03-31	$25,925	Strictly Private	t	f	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.	Lorem ipsum dolor sit amet, consectetuer adipiscing
18	Bodn FQA	30	50	16	1	2	92	2021-11-16	2020-12-12	$96,301	Strictly Private	t	t	Lorem ipsum dolor sit amet, consectetuer	Lorem ipsum dolor sit amet, consectetuer adipiscing
19	Web/Mobile	5	43	4	2	2	86	2022-08-15	2020-03-30	$93,438	Strictly Private	t	t	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur	Lorem ipsum dolor sit amet, consectetuer
20	Bodn FQA	7	39	3	2	5	115	2022-08-15	2022-04-13	$93,129	Standard	f	t	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur sed
21	Bodn FQA	2	34	3	4	3	11	2022-09-01	2021-09-19	$93,462	On Request	f	f	Lorem ipsum dolor sit amet,	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur sed
22	Bodn FQA	5	53	17	7	3	72	2021-11-19	2022-02-11	$41,065	On Request	t	t	Lorem ipsum dolor sit amet, consectetuer adipiscing	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur
23	Web/Mobile	2	3	1	5	8	62	2021-03-23	2023-04-24	$59,950	On Request	f	f	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur	Lorem ipsum dolor sit amet,
24	Bodn FQA	21	30	3	2	10	49	2021-05-09	2020-12-07	$59,876	On Request	t	f	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur sed	Lorem ipsum dolor sit amet, consectetuer adipiscing
25	Bodn FQA	3	51	19	2	7	5	2022-06-04	2023-04-17	$76,409	Standard	f	f	Lorem ipsum dolor sit amet, consectetuer adipiscing	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
26	Web/Mobile	14	41	5	2	3	199	2021-07-19	2021-07-10	$26,427	On Request	t	f	Lorem ipsum dolor sit amet,	Lorem ipsum dolor sit amet, consectetuer adipiscing
27	Web/Mobile	16	44	8	3	9	167	2021-08-16	2021-05-03	$71,269	On Request	f	f	Lorem ipsum dolor sit amet, consectetuer adipiscing	Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
28	Web/Mobile	14	2	5	2	5	42	2020-12-31	2020-04-17	$36,292	On Request	f	t	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur sed	Lorem ipsum dolor sit amet, consectetuer adipiscing
29	Bodn FQA	24	15	17	7	4	119	2022-10-29	2022-09-09	$90,140	Standard	f	f	Lorem ipsum dolor sit amet, consectetuer adipiscing	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur
30	Web/Mobile	14	35	4	5	8	165	2021-04-08	2023-03-06	$85,649	On Request	f	t	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur sed	Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur
\.


--
-- Name: projects_project_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.projects_project_id_seq', 30, true);


--
-- Name: projects projects_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.projects
    ADD CONSTRAINT projects_pkey PRIMARY KEY (project_id);


--
-- PostgreSQL database dump complete
--

