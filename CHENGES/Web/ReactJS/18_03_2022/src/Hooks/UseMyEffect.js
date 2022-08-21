import { useRef } from "react";

const useMyEffect = (cb, dplist) => {
  const prevDep = useRef(dplist);
  const prevcb = useRef(cb);
  if (dplist.some((value, index) => prevDep.current[index] !== value)) {
    prevDep.current = dplist;
    prevcb.current();
    prevcb.current = cb();
  }
};

export default useMyEffect();
